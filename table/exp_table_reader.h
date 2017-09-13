#pragma once

#include <util/file_reader_writer.h>
#include <util/arena.h>
#include "table_reader.h"

using std::unique_ptr;

namespace rocksdb {

struct ExperimentalTableReaderFileInfo {
  Slice file_data;
  uint32_t data_end_offset;
  unique_ptr<RandomAccessFileReader> file;
};

class ExperimentalTableReader : public TableReader {
 public:
  ExperimentalTableReader() {};

  virtual ~ExperimentalTableReader() { }

  virtual InternalIterator* NewIterator(const ReadOptions&,
                                        Arena arena = nullptr,
                                        bool skip_filters = false);

  virtual InternalIterator* NewRangeTombstoneIterator(
      const ReadOptions& read_options);

  virtual uint64_t ApproximateOffsetOf(const Slice& key);

  virtual void SetupForCompaction();

  virtual std::shared_ptr<const TableProperties> GetTableProperties() const;

  virtual void Prepare(const Slice& target);

  virtual size_t ApproximateMemoryUsage() const;

  virtual Status Get(const ReadOptions& read_options, const Slice& key,
                     GetContext* get_context, bool skip_filter = false);

  virtual Status Prefetch(const Slice* begin = nullptr,
                          const Slice* end = nullptr);

  virtual Status DumpTable(WritableFile* out_file);

  virtual Status VerifyChecksum();

  virtual void Close();

  Status status();

 private:
  Status status_;
};

} // namespace rocksdb
#pragma once

#include "rocksdb/options.h"
#include "rocksdb/status.h"
#include "rocksdb/table.h"
#include "rocksdb/table_properties.h"
#include "table/table_builder.h"

namespace rocksdb {

class NaiveTableBuilder : public TableBuilder {
 public:
  NaiveTableBuilder(const ImmutableCFOptions& ioptions,
                    uint32_t column_family_id, WritableFileWriter* file,
                    uint32_t user_key_len, const std::string& column_family_name);

  ~NaiveTableBuilder() { }

  void Add(const Slice& key, const Slice& value) override;

  Status status() const override;

  Status Finish() override;

  void Abandon() override;

  uint64_t NumEntries() const override;

  uint64_t FileSize() const override;

 private:
  const ImmutableCFOptions& ioptions_;
  WritableFileWriter* file_;
  uint64_t offset_ = 0;
  Status status_;
  TableProperties properties_;
  bool closed_ = false;



  NaiveTableBuilder(const NaiveTableBuilder&) = delete;
  void operator=(const NaiveTableBuilder&) = delete;

};

} // namespace rocksdb

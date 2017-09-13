#pragma once

#include "rocksdb/table.h"

using std::unique_ptr;

namespace rocksdb {

class ExperimentalTableFactory : public TableFactory {
 public:
  ~ExperimentalTableFactory() {}

  explicit ExperimentalTableFactory(
      const ExperimentalTableOptions& _table_options = ExperimentalTableOptions())
      : table_options_(_table_options) {}

  const char* Name() const override { return "ExperimentalTable"; }

  Status NewTableReader(const TableReaderOptions& table_reader_options,
                        unique_ptr<RandomAccessFileReader>&& file,
                        uint64_t file_size, unique_ptr<TableReader>* table,
                        bool prefetch_index_and_filter_in_cache) const override;

  TableBuilder* NewTableBuilder(const TableBuilderOptions& table_builder_options,
                                uint32_t column_family_id,
                                WritableFileWriter* file) const override;

  std::string GetPrintableTableOptions() const override;

  const ExperimentalTableOptions& table_options() const;

  Status SanitizeOptions(const DBOptions& dp_opts,
                         const ColumnFamilyOptions& cf_opts) const override {
    return Status::OK();
  }

  void* GetOptions() override { return &table_options_; }

  Status GetOptionString(std::string* opt_string,
                         const std::string& delimiter) const override {
    return Status::OK();
  }

 private:
  ExperimentalTableOptions table_options_;
};

struct ExperimentalTableOptions {
};

} // namespace rocksdb

//
// Created by olzhas on 9/12/17.
//

#include "exp_table_factory.h"
#include "exp_table_builder.h"
#include "exp_table_reader.h"

namespace rocksdb {

Status ExperimentalTableFactory::NewTableReader(
    const rocksdb::TableReaderOptions &table_reader_options,
    unique_ptr<rocksdb::RandomAccessFileReader> &&file,
    uint64_t file_size, unique_ptr<rocksdb::TableReader> *table,
    bool prefetch_index_and_filter_in_cache) const {
  std::unique_ptr<ExperimentalTableReader> new_reader(new ExperimentalTableReader());
  Status s = new_reader->status();
  return s;
}

TableBuilder *ExperimentalTableFactory::NewTableBuilder(
    const rocksdb::TableBuilderOptions &table_builder_options,
    uint32_t column_family_id, rocksdb::WritableFileWriter *file) const {
  return new ExperimentalTableBuilder(
      table_builder_options.ioptions, column_family_id, file,
      0, table_builder_options.column_family_name);
}

std::string ExperimentalTableFactory::GetPrintableTableOptions() const {
  return std::__cxx11::string();
}

const ExperimentalTableOptions &ExperimentalTableFactory::table_options() const {
  return table_options_;
}

} // namespace rocksdb
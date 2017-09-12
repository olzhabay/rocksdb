//
// Created by olzhas on 9/12/17.
//

#include "naive_table_factory.h"

namespace rocksdb {

Status NaiveTableFactory::NewTableReader(
    const rocksdb::TableReaderOptions &table_reader_options,
    unique_ptr<rocksdb::RandomAccessFileReader> &&file,
    uint64_t file_size, unique_ptr<rocksdb::TableReader> *table,
    bool prefetch_index_and_filter_in_cache) const {
  return rocksdb::Status();
}

TableBuilder *NaiveTableFactory::NewTableBuilder(
    const rocksdb::TableBuilderOptions &table_builder_options,
    uint32_t column_family_id, rocksdb::WritableFileWriter *file) const {

  return nullptr;
}

std::string NaiveTableFactory::GetPrintableTableOptions() const {
  return std::__cxx11::string();
}

const NaiveTableOptions &NaiveTableFactory::table_options() const {
  return table_options_;
}

} // namespace rocksdb
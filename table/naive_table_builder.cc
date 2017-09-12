#include "naive_table_builder.h"

namespace rocksdb {

NaiveTableBuilder::NaiveTableBuilder(
    const ImmutableCFOptions &ioptions, uint32_t column_family_id,
    WritableFileWriter *file, uint32_t user_key_len,
    const std::string &column_family_name)
    : ioptions_(ioptions),
      file_(file) {
  properties_.fixed_key_len = user_key_len;
  properties_.index_size = 0;
  properties_.filter_size = 0;
  properties_.format_version = 0;
  properties_.column_family_id = column_family_id;
  properties_.column_family_name = column_family_name;
}

void NaiveTableBuilder::Add(const Slice &key, const Slice &value) {

}

Status NaiveTableBuilder::status() const {
  return Status();
}

Status NaiveTableBuilder::Finish() {
  return Status();
}

void NaiveTableBuilder::Abandon() {

}

uint64_t NaiveTableBuilder::NumEntries() const {
  return 0;
}

uint64_t NaiveTableBuilder::FileSize() const {
  return 0;
}


} // namespace rocksdb
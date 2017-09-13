#include "exp_table_reader.h"

namespace rocksdb {


InternalIterator *ExperimentalTableReader::NewIterator(const ReadOptions &, Arena arena, bool skip_filters) {
  return nullptr;
}

InternalIterator *ExperimentalTableReader::NewRangeTombstoneIterator(const ReadOptions &read_options) {
  return TableReader::NewRangeTombstoneIterator(read_options);
}

uint64_t ExperimentalTableReader::ApproximateOffsetOf(const Slice &key) {
  return 0;
}

void ExperimentalTableReader::SetupForCompaction() {

}

std::shared_ptr<const TableProperties> ExperimentalTableReader::GetTableProperties() const {
  return shared_ptr<const TableProperties>();
}

void ExperimentalTableReader::Prepare(const Slice &target) {
  TableReader::Prepare(target);
}

size_t ExperimentalTableReader::ApproximateMemoryUsage() const {
  return 0;
}

Status ExperimentalTableReader::Get(const ReadOptions &read_options,
                                    const Slice &key, GetContext *get_context,
                                    bool skip_filter) {
  return Status();
}

Status ExperimentalTableReader::Prefetch(const Slice *begin, const Slice *end) {
  return TableReader::Prefetch(begin, end);
}

Status ExperimentalTableReader::DumpTable(WritableFile *out_file) {
  return TableReader::DumpTable(out_file);
}

Status ExperimentalTableReader::VerifyChecksum() {
  return TableReader::VerifyChecksum();
}

void ExperimentalTableReader::Close() {
  TableReader::Close();
}

Status ExperimentalTableReader::status() {
  return status_;
}

} // namespace rocksdb
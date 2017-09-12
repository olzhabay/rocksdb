#include <include/rocksdb/memtablerep.h>
#include "nv_skiplist.h"

namespace rocksdb {



MemTableRep* NVSkipListFactory::CreateMemTableRep(
  const MemTableRep::KeyComparator& compare, Allocator* allocator,
  const SliceTransform* transform, Logger* logger) {
  return new NVSkipListRep(compare, allocator, transform, lookahead_);
}

KeyHandle NVSkipListRep::Allocate(const size_t len, char **buf) {
  return MemTableRep::Allocate(len, buf);
}

void NVSkipListRep::Insert(KeyHandle handle) {

}

void NVSkipListRep::InsertWithHint(KeyHandle handle, void **hint) {
  MemTableRep::InsertWithHint(handle, hint);
}

void NVSkipListRep::InsertConcurrently(KeyHandle handle) {
  MemTableRep::InsertConcurrently(handle);
}

void NVSkipListRep::MarkReadOnly() {
  MemTableRep::MarkReadOnly();
}

void NVSkipListRep::Get(const LookupKey &k, void *callback_args, bool (*callback_func)(void *, const char *)) {
  MemTableRep::Get(k, callback_args, callback_func);
}

uint64_t NVSkipListRep::ApproximateNumEntries(const Slice &start_ikey, const Slice &end_key) {
  return MemTableRep::ApproximateNumEntries(start_ikey, end_key);
}

size_t NVSkipListRep::ApproximateMemoryUsage() {
  return 0;
}

NVSkipListRep::Iterator *NVSkipListRep::GetIterator(Arena *arena) {
  return nullptr;
}

bool NVSkipListRep::Contains(const char *key) const {
  return false;
}
} // namespace rocksdb
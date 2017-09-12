#include <include/rocksdb/memtablerep.h>
#include "nv_skiplist.h"

namespace rocksdb {



MemTableRep* NVSkipListFactory::CreateMemTableRep(
  const MemTableRep::KeyComparator& compare, Allocator* allocator,
  const SliceTransform* transform, Logger* logger) {
  return new NVSkipListRep(compare, allocator, transform, lookahead_);
}

} // namespace rocksdb
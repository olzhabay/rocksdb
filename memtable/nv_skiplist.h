#pragma once


namespace rocksdb {

namespace {
class NVSkipListRep : public MemTableRep {
  const MemTableRep::KeyComparator& cmp_;
  const SliceTransform* transform_;
  const size_t lookahead_;

 public:
  explicit NVSkipListRep(const MemTableRep::KeyComparator& compare,
                         Allocator* allocator, const SliceTransform* transform,
                         const size_t lookahead) 
  : MemTableRep(allocator),
    cmp_(compare),
    transform_(transform),
    lookahead_(lookahead) {}
  
  
};


}
} // namespace rocksdb
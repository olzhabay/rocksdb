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

  virtual KeyHandle Allocate(const size_t len, char** buf);

  virtual void Insert(KeyHandle handle);

  virtual void InsertWithHint(KeyHandle handle, void** hint);

  virtual void InsertConcurrently(KeyHandle handle);

  virtual bool Contains(const char* key) const;

  virtual void MarkReadOnly();

  virtual void Get(const LookupKey& k, void* callback_args,
                   bool (*callback_func)(void* arg, const char* entry));

  virtual uint64_t ApproximateNumEntries(const Slice& start_ikey,
                                         const Slice& end_key);

  virtual size_t ApproximateMemoryUsage();

  virtual ~NVSkipListRep() override {}

  class Iterator : public MemTableRep::Iterator{
   public:
    virtual ~Iterator() {}

    virtual bool Valid() const = 0;

    virtual const char* key() const = 0;

    virtual void Next() = 0;

    virtual void Prev() = 0;

    virtual void Seek(const Slice& internal_key, const char* memtable_key) = 0;

    virtual void SeekForPrev(const Slice& internal_key,
                             const char* memtable_key) = 0;

    virtual void SeekToFirst() = 0;

    virtual void SeekToLast() = 0;
  };

  virtual Iterator* GetIterator(Arena* arena = nullptr);



};


}
} // namespace rocksdb
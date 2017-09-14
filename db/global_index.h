#pragma once

namespace rocksdb {

class GlobalIndex {
 public:

  virtual ~GlobalIndex() = 0;

  virtual void Add() = 0;

  virtual void* Get() = 0;

  virtual void Update() = 0;

  virtual void Delete() = 0;

};

} // namespace rocksdb
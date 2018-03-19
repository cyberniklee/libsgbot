/* Created slam/hector/map/gridmap/cache.h by CybernikLee
 *
 * E-Mail <cyberniklee@gmail.com>
 *
 * Copyright 2018 GuangZhou SmartGiant Tech 
 * 
 */

#ifndef _SLAM_HECTOR_MAP_GRIDMAP_CACHE_H_
#define _SLAM_HECTOR_MAP_GRIDMAP_CACHE_H_

#include <common/exception.h>

namespace sgbot {
namespace slam {
namespace hector {

  class CachedMapElement{
  public:
    int index;
    float value;
  };

  class GridMapCache {
  public:
    GridMapCache()
      : cache_array_(NULL), width_(-1), height_(-1), current_index_(0)
    {}

    virtual ~GridMapCache()
    {

    }

    void resetCache()
    {
      current_index_++;
    }

    bool containsCachedData(int index, float& value)
    {
      const CachedMapElement& element(cache_array_[index]);

      if(element.index == current_index_)
      {
        value = element.value;
        return true;
      }
      else
      {
        return false;
      }
    }

    void cacheData(int index, float value)
    {
      CachedMapElement& element(cache_array_[index]);
      element.index = current_index_;
      element.value = value;
    }

    void setMapSize(const int width, const int height)
    {
      setCacheSize(width, height);
    }

  protected:

    void createCache(const int width, const int height)
    {
      width_ = width;
      height_ = height;

      int size_total = width * height;

      cache_array_ = new CachedMapElement[size_total];

      for(int i = 0; i < size_total; ++i)
      {
        cache_array_[i].index = -1;
      }
    }

    void deleteCache()
    {
      if(cache_array_ != NULL)
        delete[] cache_array_;
    }

    void setCacheSize(const int width, const int height)
    {
      if(!(width_ == width && height_ == height))
      {
        if(cache_array_ != NULL)
        {
          deleteCache();
          cache_array_ = NULL;
        }
        createCache(width, height);
      }
    }

  private:
    int current_index_;
    CachedMapElement* cache_array_;
    int width_, height_;
  };  // class GridMapCache

}  // namespace hector
}  // namespace slam
}  // namespace sgbot

#endif  // _SLAM_HECTOR_MAP_GRIDMAP_CACHE_H_
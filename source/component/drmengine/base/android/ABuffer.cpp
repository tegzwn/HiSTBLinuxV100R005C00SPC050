/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ABuffer.h"

//#include <ALooper.h>
//#include "AMessage.h"
#include "MediaBufferBase.h"

namespace android {

ABuffer::ABuffer(size_t capacity)
    : mMediaBufferBase(NULL),
      mRangeOffset(0),
      mInt32Data(0),
      mOwnsData(true) {
    mData = malloc(capacity);
    if (mData == NULL) {
        mCapacity = 0;
        mRangeLength = 0;
    } else {
        mCapacity = capacity;
        mRangeLength = capacity;
    }
}

ABuffer::ABuffer(void *data, size_t capacity)
    : mMediaBufferBase(NULL),
      mData(data),
      mCapacity(capacity),
      mRangeOffset(0),
      mRangeLength(capacity),
      mInt32Data(0),
      mOwnsData(false) {
}

// static
sp<ABuffer> ABuffer::CreateAsCopy(const void *data, size_t capacity)
{
    sp<ABuffer> res = new ABuffer(capacity);
    if (res->base() == NULL) {
        return NULL;
    }
    memcpy(res->data(), data, capacity);
    return res;
}

ABuffer::~ABuffer() {
    if (mOwnsData) {
        if (mData != NULL) {
            free(mData);
            mData = NULL;
        }
    }
    setMediaBufferBase(NULL);
}

void ABuffer::setRange(size_t offset, size_t size) {

    mRangeOffset = offset;
    mRangeLength = size;
}

MediaBufferBase *ABuffer::getMediaBufferBase() {
    if (mMediaBufferBase != NULL) {
        mMediaBufferBase->add_ref();
    }
    return mMediaBufferBase;
}

void ABuffer::setMediaBufferBase(MediaBufferBase *mediaBuffer) {
    if (mMediaBufferBase != NULL) {
        mMediaBufferBase->release();
    }
    mMediaBufferBase = mediaBuffer;
}

}  // namespace android

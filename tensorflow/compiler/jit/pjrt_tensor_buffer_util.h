/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_JIT_PJRT_TENSOR_BUFFER_UTIL_H_
#define TENSORFLOW_COMPILER_JIT_PJRT_TENSOR_BUFFER_UTIL_H_

#include <memory>

#include "tensorflow/compiler/xla/pjrt/pjrt_client.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"

namespace tensorflow {

// Takes the device memory pointer from the PjRtBuffer and create a Tensor that
// contains a PjRtTensorBuffer. The PjRtTensorBuffer holds the pointer to the
// device memory. It also owns the PjRtBuffer.
//
// TODO(b/289001822): Create a unit test to cover this function.
Tensor MakeTensorFromPjRtStreamExecutorBuffer(
    DataType dtype, const TensorShape& shape,
    std::unique_ptr<xla::PjRtBuffer> pjrt_buffer);

}  // namespace tensorflow

#endif  // TENSORFLOW_COMPILER_JIT_PJRT_TENSOR_BUFFER_UTIL_H_
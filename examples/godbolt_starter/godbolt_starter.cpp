//@HEADER
// ************************************************************************
//
//                        Kokkos v. 4.0
//       Copyright (2022) National Technology & Engineering
//               Solutions of Sandia, LLC (NTESS).
//
// Under the terms of Contract DE-NA0003525 with NTESS,
// the U.S. Government retains certain rights in this software.
//
// Part of Kokkos, under the Apache License v2.0 with LLVM Exceptions.
//
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//@HEADER

#if defined(_MDSPAN_USE_CLASS_TEMPLATE_ARGUMENT_DEDUCTION)
// https://godbolt.org/z/ehErvsTce
#include <experimental/mdspan>
#include <iostream>

namespace stdex = std::experimental;

int main() {
  std::array d{
    0, 5, 1,
    3, 8, 4,
    2, 7, 6,
  };

  stdex::mdspan m{d.data(), stdex::extents{3, 3}};

  for (std::size_t i = 0; i < m.extent(0); ++i)
    for (std::size_t j = 0; j < m.extent(1); ++j)
      std::cout << "m(" << i << ", " << j << ") == " << m(i, j) << "\n";
}
#else
int main() {}
#endif

// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2012 Preferred Infrastracture and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#include "anomaly_base.hpp"
#include <algorithm>
#include <cmath>
#include "../common/vector_util.hpp"

using namespace std;
using namespace pfi::data;

namespace jubatus {
namespace anomaly {

const uint32_t anomaly_base::neighbor_num_ = 10;

anomaly_base::anomaly_base() {
}

anomaly_base::~anomaly_base() {
}

void anomaly_base::save(std::ostream& os) {
  pfi::data::serialization::binary_oarchive oa(os);
  oa << orig_;
  save_impl(os);
}

void anomaly_base::load(std::istream& is) {
  pfi::data::serialization::binary_iarchive ia(is);
  ia >> orig_;
  load_impl(is);
}

} // namespace anomaly
} // namespace jubatus

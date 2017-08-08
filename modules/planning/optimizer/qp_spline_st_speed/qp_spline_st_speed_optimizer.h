/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/

#ifndef MODULES_PLANNING_OPTIMIZER_QP_SPLINE_ST_QP_SPLINE_ST_SPEED_OPTIMIZER_H_
#define MODULES_PLANNING_OPTIMIZER_QP_SPLINE_ST_QP_SPLINE_ST_SPEED_OPTIMIZER_H_

#include <string>

#include "modules/common/configs/proto/vehicle_config.pb.h"
#include "modules/planning/proto/qp_spline_st_speed_config.pb.h"
#include "modules/planning/proto/st_boundary_config.pb.h"

#include "modules/planning/optimizer/speed_optimizer.h"
#include "modules/planning/optimizer/st_graph/st_boundary_mapper.h"

namespace apollo {
namespace planning {

class QpSplineStSpeedOptimizer : public SpeedOptimizer {
 public:
  explicit QpSplineStSpeedOptimizer(const std::string& name);

  bool Init() override;

 private:
  common::Status Process(const PathData& path_data,
                         const apollo::common::TrajectoryPoint& init_point,
                         const ReferenceLine& reference_line,
                         PathDecision* const path_decision,
                         SpeedData* const speed_data) override;

  void RecordSTGraphDebug(const std::vector<StGraphBoundary>& boundaries,
                          const SpeedLimit& speed_limits,
                          const SpeedData& speed_data);

  QpSplineStSpeedConfig qp_spline_st_speed_config_;
  StBoundaryConfig st_boundary_config_;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_OPTIMIZER_QP_SPLINE_ST_QP_SPLINE_ST_SPEED_OPTIMIZER_H_

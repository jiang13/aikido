#include "aikido/planner/optimization/SplineVariables.hpp"
#include <dart/dynamics/dynamics.hpp>
#include <aikido/statespace/dart/MetaSkeletonStateSpace.hpp>

namespace aikido {
namespace planner {
namespace optimization {

//==============================================================================
SplineVariables::SplineVariables(const trajectory::Spline& splineToClone)
//  : mSpline(static_cast<const trajectory::Spline&>(*(splineToClone.clone().release())))
//    : mSpline(std::make_shared<statespace::dart::MetaSkeletonStateSpace>(dart::dynamics::Skeleton::create("skel")))
    : mSpline(std::make_shared<statespace::dart::MetaSkeletonStateSpace>(std::dynamic_pointer_cast<statespace::dart::MetaSkeletonStateSpace>(splineToClone.getStateSpace())->getMetaSkeleton()))
{
  // Do nothing
}

//==============================================================================
const trajectory::Trajectory& SplineVariables::getTrajectory() const
{
  return static_cast<const trajectory::Trajectory&>(mSpline);
}

//==============================================================================
const trajectory::Spline& SplineVariables::getSpline() const
{
  return mSpline;
}

//==============================================================================
std::size_t SplineVariables::getDimension() const
{
  return mDimension;
}

} // namespace optimization
} // namespace planner
} // namespace aikido

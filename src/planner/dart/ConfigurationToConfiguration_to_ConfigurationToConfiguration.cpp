#include "aikido/planner/dart/ConfigurationToConfiguration_to_ConfigurationToConfiguration.hpp"

#include <dart/dynamics/dynamics.hpp>
#include "aikido/statespace/dart/MetaSkeletonStateSpace.hpp"

using aikido::statespace::dart::MetaSkeletonStateSpace;

namespace aikido {
namespace planner {
namespace dart {

//==============================================================================
ConfigurationToConfiguration_to_ConfigurationToConfiguration::
    ConfigurationToConfiguration_to_ConfigurationToConfiguration(
        std::shared_ptr<planner::ConfigurationToConfigurationPlanner> planner,
        ::dart::dynamics::MetaSkeletonPtr metaSkeleton)
  : PlannerAdapter<planner::ConfigurationToConfigurationPlanner,
                   planner::dart::ConfigurationToConfigurationPlanner>(
        std::move(planner), std::move(metaSkeleton))
{
  // Do nothing
}

//==============================================================================
trajectory::TrajectoryPtr
ConfigurationToConfiguration_to_ConfigurationToConfiguration::plan(
    const planner::dart::ConfigurationToConfiguration& problem,
    Planner::Result* result)
{
  // TODO: Check equality between state space of this planner and given problem.

  auto delegateProblem = planner::ConfigurationToConfiguration(
      mMetaSkeletonStateSpace,
      problem.getStartState(),
      problem.getGoalState(),
      problem.getConstraint());

  return mDelegate->plan(delegateProblem, result);
}

//==============================================================================
std::shared_ptr<Planner> ConfigurationToConfiguration_to_ConfigurationToConfiguration::clone() const
{
  throw std::runtime_error("Not implemented");
}

} // namespace dart
} // namespace planner
} // namespace aikido

#ifndef AIKIDO_CONSTRAINT_DIFFERENTIABLEPROJECTOR_H
#define AIKIDO_CONSTRAINT_DIFFERENTIABLEPROJECTOR_H

#include <Eigen/Dense>
#include "Projectable.hpp"
#include "Differentiable.hpp"

namespace aikido {
namespace constraint{

/// Uses Newton's method to project state.
class DifferentiableProjector : public Projectable
{
public:

  DifferentiableProjector(
    DifferentiablePtr _differentiable,
    int _maxIteration=1000, 
    double _tolerance=1e-4,  // These numbers seem to work for Eigen::MatrixXd.
    double _minStepSize=1e-5);

  // Documentation inherited.
  bool project(
    const statespace::StateSpace::State* _s,
    statespace::StateSpace::State* _out) const override;

  // Documentation inherited.
  statespace::StateSpacePtr getStateSpace() const override;

private:
  DifferentiablePtr mDifferentiable;
  int mMaxIteration;
  double mTolerance;
  double mMinStepSize;

  bool contains(const statespace::StateSpace::State* _s) const;
};


} // constraint
} // aikido

#endif

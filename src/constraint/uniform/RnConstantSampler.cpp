#include "aikido/constraint/uniform/RnConstantSampler.hpp"

namespace aikido {
namespace constraint {
namespace uniform {

template class RConstantSampler<0>;

template class RConstantSampler<1>;

template class RConstantSampler<2>;

template class RConstantSampler<3>;

template class RConstantSampler<6>;

template class RConstantSampler<Eigen::Dynamic>;

} // namespace uniform
} // namespace constraint
} // namespace aikido

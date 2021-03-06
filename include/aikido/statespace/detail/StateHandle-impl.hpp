#include "aikido/statespace/StateHandle.hpp"

namespace aikido {
namespace statespace {

//==============================================================================
template <class StateSpace, class QualifiedState>
StateHandle<StateSpace, QualifiedState>::StateHandle()
  : StateHandle(nullptr, nullptr)
{
  // Do nothing
}

//==============================================================================
template <class StateSpace, class QualifiedState>
StateHandle<StateSpace, QualifiedState>::StateHandle(
    const StateSpace* space, QualifiedState* state)
  : mSpace(space), mState(state)
{
  // Do nothing
}

//==============================================================================
template <class StateSpace, class QualifiedState>
StateHandle<StateSpace, QualifiedState>::operator QualifiedState*() const
{
  return mState;
}

//==============================================================================
template <class StateSpace, class QualifiedState>
void StateHandle<StateSpace, QualifiedState>::reset()
{
  reset(nullptr, nullptr);
}

//==============================================================================
template <class StateSpace, class QualifiedState>
void StateHandle<StateSpace, QualifiedState>::reset(
    const StateSpace* space, QualifiedState* state)
{
  mSpace = space;
  mState = state;
}

//==============================================================================
template <class StateSpace, class QualifiedState>
template <typename Q>
auto StateHandle<StateSpace, QualifiedState>::getState() ->
    typename std::enable_if<!std::is_const<Q>::value, Q*>::type
{
  return mState;
}

//==============================================================================
template <class StateSpace, class QualifiedState>
template <typename Q>
auto StateHandle<StateSpace, QualifiedState>::getState() const ->
    typename std::conditional<std::is_const<Q>::value, Q*, const Q*>::type
{
  return mState;
}

//==============================================================================
template <class _StateSpace, class _QualifiedState>
auto StateHandle<_StateSpace, _QualifiedState>::getStateSpace() const
    -> const StateSpace*
{
  return mSpace;
}

} // namespace statespace
} // namespace aikido

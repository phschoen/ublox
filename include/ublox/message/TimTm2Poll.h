//
// Copyright 2015 - 2017 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/// @file
/// @brief Contains definition of TIM-TM2 (@b poll) message and its fields.

#pragma once

#include "ublox/Message.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the TIM-TM2 (@b poll) message fields.
/// @see TimTm2Poll
struct TimTm2PollFields
{
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<>;
};

/// @brief Definition of TIM-TM2 (@b poll) message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref TimTm2PollFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class TimTm2Poll : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_TIM_TM2>,
        comms::option::FieldsImpl<TimTm2PollFields::All>,
        comms::option::MsgType<TimTm2Poll<TMsgBase> >
    >
{
public:

    /// @brief Default constructor
    TimTm2Poll() = default;

    /// @brief Copy constructor
    TimTm2Poll(const TimTm2Poll&) = default;

    /// @brief Move constructor
    TimTm2Poll(TimTm2Poll&& other) = default;

    /// @brief Destructor
    ~TimTm2Poll() = default;

    /// @brief Copy assignment
    TimTm2Poll& operator=(const TimTm2Poll&) = default;

    /// @brief Move assignment
    TimTm2Poll& operator=(TimTm2Poll&&) = default;
};


}  // namespace message

}  // namespace ublox


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
/// @brief Contains definition of CFG-RINV message and its fields.

#pragma once

#include "ublox/Message.h"
#include "ublox/field/common.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the CFG-RINV message fields.
/// @see CfgRinv
struct CfgRinvFields
{
    /// @brief Definition of "flags" field.
    struct flags : public
        field::common::X1T<
            comms::option::BitmaskReservedBits<0xfc, 0>
        >
    {
        /// @brief Provide names for internal bits.
        /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
        ///     related to @b comms::field::BitmaskValue class from COMMS library
        ///     for details.
        COMMS_BITMASK_BITS_SEQ(dump, binary);
    };

    /// @brief Definition of "data" field.
    /// @tparam TOpt Extra option(s)
    template <typename TOpt = comms::option::EmptyOption>
    using data =
        field::common::ListT<std::uint8_t, TOpt>;

    /// @brief All the fields bundled in std::tuple.
    /// @tparam TOpt Extra option(s) for @ref data field
    template <typename TOpt>
    using All = std::tuple<
        flags,
        data<TOpt>
    >;
};

/// @brief Definition of CFG-RINV message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref CfgRinvFields and for definition of the fields this message contains
///         and COMMS_MSG_FIELDS_ACCESS() for fields access details.
/// @tparam TMsgBase Common interface class for all the messages.
/// @tparam TDataOpt Extra option(s) for @b bytes field
template <typename TMsgBase = Message, typename TDataOpt = comms::option::EmptyOption>
class CfgRinv : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_RINV>,
        comms::option::FieldsImpl<CfgRinvFields::All<TDataOpt> >,
        comms::option::MsgType<CfgRinv<TMsgBase, TDataOpt> >
    >
{
public:

    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The field names are:
    ///     @li @b flags for @ref CfgRinvFields::flags field
    ///     @li @b data for @ref CfgRinvFields::data field
    COMMS_MSG_FIELDS_ACCESS(flags, data);

    /// @brief Default constructor
    CfgRinv() = default;

    /// @brief Copy constructor
    CfgRinv(const CfgRinv&) = default;

    /// @brief Move constructor
    CfgRinv(CfgRinv&& other) = default;

    /// @brief Destructor
    ~CfgRinv() = default;

    /// @brief Copy assignment
    CfgRinv& operator=(const CfgRinv&) = default;

    /// @brief Move assignment
    CfgRinv& operator=(CfgRinv&&) = default;
};


}  // namespace message

}  // namespace ublox


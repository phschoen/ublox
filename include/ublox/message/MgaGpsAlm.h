//
// Copyright 2017 (C). Alex Robenko. All rights reserved.
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
/// @brief Contains definition of MGA-GPS-ALM message and its fields.

#pragma once

#include "ublox/Message.h"
#include "ublox/field/common.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the MGA-GPS-ALM message fields.
/// @see MgaGpsAlm
struct MgaGpsAlmFields
{
    /// @brief Definition of "type" field.
    using type  =
    field::common::U1T<
        comms::option::ValidNumValueRange<2, 2>,
        comms::option::DefaultNumValue<2>,
        comms::option::FailOnInvalid<>
    >;

    /// @brief Definition of "version" field.
    using version =
        field::common::U1T<
            comms::option::ValidNumValueRange<0, 0>
        >;

    /// @brief Definition of "svId" field.
    using svId = field::common::U1;

    /// @brief Definition of "svHealth" field.
    using svHealth = field::common::U1;

    /// @brief Definition of "e" field.
    using e = field::common::U2T<comms::option::ScalingRatio<1, 0x200000> >;

    /// @brief Definition of "almWNa" field.
    using almWNa = field::common::U1T<comms::option::UnitsWeeks>;

    /// @brief Definition of "toa" field.
    using toa =
        field::common::U1T<
            comms::option::ScalingRatio<1, 0x1000>,
            comms::option::UnitsSeconds
        >;

    /// @brief Definition of "deltaI" field.
    using deltaI = field::common::I2T<comms::option::ScalingRatio<1, 0x80000> >;

    /// @brief Definition of "omegaDot" field.
    using omegaDot = field::common::I2T<comms::option::ScalingRatio<1, 0x4000000000ULL> >;

    /// @brief Definition of "sqrtA" field.
    using sqrtA = field::common::U4T<comms::option::ScalingRatio<1, 0x800> >;

    /// @brief Definition of "omega0" field.
    using omega0 = field::common::I4T<comms::option::ScalingRatio<1, 0x800000> >;

    /// @brief Definition of "omega" field.
    using omega = omega0;

    /// @brief Definition of "m0" field.
    using m0 = field::common::I4T<comms::option::ScalingRatio<1, 0x800000> >;

    /// @brief Definition of "af0" field.
    using af0 =
        field::common::I2T<
            comms::option::ScalingRatio<1, 0x100000>,
            comms::option::UnitsSeconds
        >;

    /// @brief Definition of "af1" field.
    using af1 =
        field::common::I2T<
            comms::option::ScalingRatio<1, 0x4000000000ULL>,
            comms::option::UnitsSeconds
        >;

    /// @brief Definition of "reserved1" field.
    using reserved1 = field::common::res4;

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        type,
        version,
        svId,
        svHealth,
        e,
        almWNa,
        toa,
        deltaI,
        omegaDot,
        sqrtA,
        omega0,
        omega,
        m0,
        af0,
        af1,
        reserved1
    >;
};

/// @brief Definition of MGA-GPS-ALM message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref MgaGpsAlmFields and for definition of the fields this message contains
///         and COMMS_MSG_FIELDS_ACCESS() for fields access details.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class MgaGpsAlm : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_MGA_GPS>,
        comms::option::FieldsImpl<MgaGpsAlmFields::All>,
        comms::option::MsgType<MgaGpsAlm<TMsgBase> >
    >
{
public:

    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The field names are:
    ///     @li @b type for @ref MgaGpsAlmFields::type field
    ///     @li @b version for @ref MgaGpsAlmFields::version field
    ///     @li @b svId for @ref MgaGpsAlmFields::svId field
    ///     @li @b svHealth for @ref MgaGpsAlmFields::svHealth field
    ///     @li @b e for @ref MgaGpsAlmFields::e field
    ///     @li @b almWNa for @ref MgaGpsAlmFields::almWNa field
    ///     @li @b toa for @ref MgaGpsAlmFields::toa field
    ///     @li @b deltaI for @ref MgaGpsAlmFields::deltaI field
    ///     @li @b omegaDot for @ref MgaGpsAlmFields::omegaDot field
    ///     @li @b sqrtA for @ref MgaGpsAlmFields::sqrtA field
    ///     @li @b omega0 for @ref MgaGpsAlmFields::omega0 field
    ///     @li @b m0 for @ref MgaGpsAlmFields::m0 field
    ///     @li @b af0 for @ref MgaGpsAlmFields::af0 field
    ///     @li @b af1 for @ref MgaGpsAlmFields::af1 field
    ///     @li @b reserved1 for @ref MgaGpsAlmFields::reserved1 field
    COMMS_MSG_FIELDS_ACCESS(
        type,
        version,
        svId,
        svHealth,
        e,
        almWNa,
        toa,
        deltaI,
        omegaDot,
        sqrtA,
        omega0,
        omega,
        m0,
        af0,
        af1,
        reserved1
    );

    /// @brief Default constructor
    MgaGpsAlm() = default;

    /// @brief Copy constructor
    MgaGpsAlm(const MgaGpsAlm&) = default;

    /// @brief Move constructor
    MgaGpsAlm(MgaGpsAlm&& other) = default;

    /// @brief Destructor
    ~MgaGpsAlm() = default;

    /// @brief Copy assignment
    MgaGpsAlm& operator=(const MgaGpsAlm&) = default;

    /// @brief Move assignment
    MgaGpsAlm& operator=(MgaGpsAlm&&) = default;
};

}  // namespace message

}  // namespace ublox


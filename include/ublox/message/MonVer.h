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
/// @brief Contains definition of MON-VER message and its fields.
#pragma once

#include "ublox/Message.h"
#include "ublox/field/common.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the MON-VER message fields.
/// @see MonVer
struct MonVerFields
{
    /// @brief Definition of "swVersion" field.
    /// @tparam TOpt Extra option(s)
    template <typename TOpt = comms::option::EmptyOption>
    using swVersion = field::common::ZString<30, TOpt>;

    /// @brief Definition of "hwVersion" field.
    /// @tparam TOpt Extra option(s)
    template <typename TOpt = comms::option::EmptyOption>
    using hwVersion = field::common::ZString<10, TOpt>;

    /// @brief Definition of "extensions" field.
    /// @tparam TListOpt Extra option(s) for the list
    /// @tparam TStrOpt Extra option(s) for the string
    template <
        typename TListOpt = comms::option::EmptyOption,
        typename TStrOpt = comms::option::EmptyOption>
    using extensions =
        field::common::ListT<
            field::common::ZString<30, TStrOpt>,
            TListOpt
        >;

    /// @brief All the fields bundled in std::tuple.
    /// @tparam TSwVerOpt Extra option(s) for @ref swVersion field
    /// @tparam THwVerOpt Extra option(s) for @ref hwVersion field
    /// @tparam TExtStrOpt Extra option(s) for strings of @ref extensions field.
    /// @tparam TExtListOpt Extra option(s) for @ref extensions field
    template <
        typename TSwVerOpt,
        typename THwVerOpt,
        typename TExtStrOpt,
        typename TExtListOpt>
    using All = std::tuple<
        swVersion<TSwVerOpt>,
        hwVersion<THwVerOpt>,
        extensions<TExtListOpt, TExtStrOpt>
    >;
};

/// @brief Definition of MON-VER message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref MonVerFields and for definition of the fields this message contains
///         and COMMS_MSG_FIELDS_ACCESS() for fields access details.
/// @tparam TMsgBase Common interface class for all the messages.
/// @tparam TSwVerOpt Extra option(s) for @b swVersion field
/// @tparam THwVerOpt Extra option(s) for @b hwVersion field
/// @tparam TExtStrOpt Extra option(s) for strings of @b extensions field.
/// @tparam TExtListOpt Extra option(s) for @b TExtListOpt field
template <
    typename TMsgBase = Message,
    typename TSwVerOpt = comms::option::EmptyOption,
    typename THwVerOpt = comms::option::EmptyOption,
    typename TExtStrOpt = comms::option::EmptyOption,
    typename TExtListOpt = comms::option::EmptyOption>
class MonVer : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_MON_VER>,
        comms::option::FieldsImpl<MonVerFields::All<TSwVerOpt, THwVerOpt, TExtStrOpt, TExtListOpt> >,
        comms::option::MsgType<MonVer<TMsgBase, TSwVerOpt, THwVerOpt, TExtStrOpt, TExtListOpt> >
    >
{
public:

    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The field names are:
    ///     @li @b swVersion for @ref MonVerFields::swVersion field
    ///     @li @b hwVersion for @ref MonVerFields::hwVersion field
    ///     @li @b extensions for @ref MonVerFields::extensions field
    COMMS_MSG_FIELDS_ACCESS(swVersion, hwVersion, extensions);

    /// @brief Default constructor
    MonVer() = default;

    /// @brief Copy constructor
    MonVer(const MonVer&) = default;

    /// @brief Move constructor
    MonVer(MonVer&& other) = default;

    /// @brief Destructor
    ~MonVer() = default;

    /// @brief Copy assignment
    MonVer& operator=(const MonVer&) = default;

    /// @brief Move assignment
    MonVer& operator=(MonVer&&) = default;
};


}  // namespace message

}  // namespace ublox


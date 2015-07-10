//
// Copyright 2015 (C). Alex Robenko. All rights reserved.
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


#pragma once

#include "comms/comms.h"

#include "MsgId.h"

namespace ublox
{

class DefaultHandler;

template <typename... TOptions>
class MessageT : public
    comms::Message<
        TOptions...,
        comms::option::LittleEndian,
        comms::option::ReadIterator<const std::uint8_t*>,
        comms::option::WriteIterator<std::uint8_t*>,
        comms::option::MsgIdType<MsgId>,
        comms::option::Handler<DefaultHandler> >
{
public:
    MessageT() = default;
    MessageT(const MessageT&) = default;
    MessageT(MessageT&&) = default;
    virtual ~MessageT() = default;

    MessageT& operator=(const MessageT&) = default;
    MessageT& operator=(MessageT&&) = default;
};

typedef MessageT<> Message;


}  // namespace ublox


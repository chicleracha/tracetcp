//
// Copyright (c) 2003 L.M.Witek
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

#pragma once

#include <string>

#include "net\socket.h"
#include "ITraceOutput.h"

struct TCPTraceSettings 
{
    std::string remoteHost;
    DWORD maxHops;
    DWORD maxTimeout;
    DWORD startHop;
    bool portRange;
    DWORD startPort;
    DWORD endPort;
    DWORD pingsPerHop;
    bool noRDNS;
    bool noAntiFlood;
	bool useRawSockets;
	std::string forceGW;
	std::string forceInterface;
};

class TraceTerminator
{
    private:
        bool m_terminateTrace;
    public:
        TraceTerminator () : m_terminateTrace(false)
        {
        }

        void setTerminate()
        {
            m_terminateTrace = true;
        }

        bool isTerminated()
        {   
            return m_terminateTrace;
        }
};


void doTraceTCP (TCPTraceSettings& settings, ITraceOutput& out, TraceTerminator& terminator);

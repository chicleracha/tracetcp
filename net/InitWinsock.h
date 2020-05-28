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

#if !defined(___NET__INITWINSOCK__INCLUDED___)
#define ___NET__INITWINSOCK__INCLUDED___

#include <winsock2.h>
#include "SocketException.h"

namespace net
{
    class InitWinsock
    {
        private:
            WSAData m_wsaData;

        public:
            InitWinsock (int highVersion, int lowVersion)
            {
                int ret = WSAStartup(MAKEWORD(highVersion, lowVersion), &m_wsaData);
                if (ret != 0)
                {
                    throw SocketException ("Initialise Winsock", ret);
                }
            }

            ~InitWinsock ()
            {
                WSACleanup();
            }

            const WSAData& getWSData()
            {
                return m_wsaData;
            }
    };
}


#endif
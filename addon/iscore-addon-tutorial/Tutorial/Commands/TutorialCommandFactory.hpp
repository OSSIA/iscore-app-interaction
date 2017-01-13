#pragma once
#include <iscore/command/Command.hpp>

namespace Tutorial
{
/**
 * @brief Tutorial::CommandFactoryName
 * @return A unique key to identify the commands of this plug-in.
 */
inline const CommandGroupKey& CommandFactoryName()
{
    static const CommandGroupKey key{"Tutorial"};
    return key;
}
}

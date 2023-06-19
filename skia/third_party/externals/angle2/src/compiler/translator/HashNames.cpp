//
// Copyright 2017 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#include "compiler/translator/HashNames.h"

#include "compiler/translator/ImmutableString.h"
#include "compiler/translator/ImmutableStringBuilder.h"
#include "compiler/translator/IntermNode.h"
#include "compiler/translator/Symbol.h"

namespace sh
{

namespace
{
constexpr const ImmutableString kHashedNamePrefix("webgl_");

// Can't prefix with just _ because then we might introduce a double underscore, which is not safe
// in GLSL (ESSL 3.00.6 section 3.8: All identifiers containing a double underscore are reserved for
// use by the underlying implementation). u is short for user-defined.
constexpr const ImmutableString kUnhashedNamePrefix("_u");

ImmutableString HashName(const ImmutableString &name, ShHashFunction64 hashFunction)
{
    ASSERT(!name.empty());
    ASSERT(hashFunction);
    khronos_uint64_t number = (*hashFunction)(name.data(), name.length());

    // Build the hashed name in place.
    static const unsigned int kHexStrMaxLength = sizeof(number) * 2;
    static const size_t kHashedNameMaxLength   = kHashedNamePrefix.length() + kHexStrMaxLength;

    ImmutableStringBuilder hashedName(kHashedNameMaxLength);
    hashedName << kHashedNamePrefix;

    hashedName.appendHex(number);

    return hashedName;
}

}  // anonymous namespace

ImmutableString HashName(const ImmutableString &name,
                         ShHashFunction64 hashFunction,
                         NameMap *nameMap)
{
    if (hashFunction == nullptr)
    {
        if (name.length() + kUnhashedNamePrefix.length() > kESSLMaxIdentifierLength)
        {
            // If the identifier length is already close to the limit, we can't prefix it. This is
            // not a problem since there are no builtins or ANGLE's internal variables that would
            // have as long names and could conflict.
            return name;
        }
        ImmutableStringBuilder prefixedName(kUnhashedNamePrefix.length() + name.length());
        prefixedName << kUnhashedNamePrefix << name;
        return prefixedName;
    }
    if (nameMap)
    {
        NameMap::const_iterator it = nameMap->find(name.data());
        if (it != nameMap->end())
        {
            // TODO(oetuaho): Would be nice if we didn't need to allocate a string here.
            return ImmutableString(it->second);
        }
    }
    ImmutableString hashedName = HashName(name, hashFunction);
    if (nameMap)
    {
        (*nameMap)[name.data()] = hashedName.data();
    }
    return hashedName;
}

ImmutableString HashName(const TSymbol *symbol, ShHashFunction64 hashFunction, NameMap *nameMap)
{
    if (symbol->symbolType() == SymbolType::Empty)
    {
        return kEmptyImmutableString;
    }
    if (symbol->symbolType() == SymbolType::AngleInternal ||
        symbol->symbolType() == SymbolType::BuiltIn)
    {
        return symbol->name();
    }
    return HashName(symbol->name(), hashFunction, nameMap);
}

}  // namespace sh

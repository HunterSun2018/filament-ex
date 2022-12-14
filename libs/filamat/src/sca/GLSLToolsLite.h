/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TNT_GLSLTOOLSLITE_H
#define TNT_GLSLTOOLSLITE_H

#include <backend/DriverEnums.h>

#include <filamat/MaterialBuilder.h>

#include <string>

namespace filamat {

class GLSLToolsLite {
public:

    // Public for unit tests.
    using Property = MaterialBuilder::Property;

    /* Guess the properties that the material is using based on a naive text-based search.
     *
     * In order for this method to detect the usage of a property:
     *  1. The MaterialInputs argument to the user-defined material function must be named "material".
     *  2. The properties on "material" should be set directly, i.e., not passed via an inout qualifier
     *     to another function which sets properties (this only works if the argument to the
     *     function is also named "material").
     */
    bool findProperties(
            filament::backend::ShaderStage type,
            const utils::CString& material,
            MaterialBuilder::PropertyList& properties) const noexcept;

    /* Remove Google-style #line directives from the source string.
     *
     * Google-style #line directives use quotes to specify file names. For example:
     * #line 100 "foobar.h"
     */
    void removeGoogleLineDirectives(std::string& text) const noexcept;
};

} // namespace filamat

#endif // TNT_GLSLTOOLSLITE_H

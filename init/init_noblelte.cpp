/*
   Copyright (C) 2017 The Android Open Source Project

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <sys/_system_properties.h>
#include "property_service.h"
#include "log.h"

namespace android {
namespace init {

void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[],
    char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void vendor_load_properties() {
    std::string bootloader = android::base::GetProperty("ro.bootloader", "");

    if (bootloader.find("N920C") == 0) {
    	property_override("ro.product.device", "nobleltejv");
    } else if (bootloader.find("N920I") == 0) {
    	property_override("ro.product.device", "nobleltedv");
    } else if (bootloader.find("N920K") == 0) {
    	property_override("ro.product.device", "nobleltektt");
    } else if (bootloader.find("N920L") == 0) {
    	property_override("ro.product.device", "nobleltelgt");
    } else if (bootloader.find("N920S") == 0) {
    	property_override("ro.product.device", "noblelteskt");
    } else if (bootloader.find("N920W8") == 0) {
    	property_override("ro.product.device", "nobleltebmc");
    } else if (bootloader.find("N920T") == 0) {
    	property_override("ro.product.device", "nobleltetmo");
    } else if (bootloader.find("N920A") == 0) {
    	property_override("ro.product.device", "noblelteatt");
    } else if (bootloader.find("N9200") == 0) {
    	property_override("ro.product.device", "nobleltechn");
    } else if (bootloader.find("N9208") == 0) {
    	property_override("ro.product.device", "nobleltezt");
    } else if (bootloader.find("N920G") == 0) {
    	property_override("ro.product.device", "nobleltedd");
    } else if (bootloader.find("N920P") == 0) {
    	property_override("ro.product.device", "nobleltespr");
    } else if (bootloader.find("N920R4") == 0) {
    	property_override("ro.product.device", "noblelteusc");
    } else if (bootloader.find("N920R6") == 0) {
    	property_override("ro.product.device", "nobleltelra");
    } else if (bootloader.find("N920R7") == 0) {
    	property_override("ro.product.device", "noblelteacg");
    }
    
}

}
}

#pragma once

#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Lamp::Telemetry::Api
{
    struct Status
    {
        NormalizedFraction Intensity{0};
        bool HasOpenLoadFault = false;
        bool HasOvercurrentFault = false;
        bool HasOvertemperatureShutdownFault = false;
        bool HasUndervoltageFault = false;
        bool HasOvervoltageFault = false;
        bool HasOvertemperatureWarning = false;

        [[nodiscard]] bool HasAnyFault() const
        {
            return HasOpenLoadFault
                || HasOvercurrentFault
                || HasOvertemperatureShutdownFault
                || HasUndervoltageFault
                || HasOvervoltageFault;
        }

        [[nodiscard]] bool HasAnyWarning() const
        {
            return HasOvertemperatureWarning;
        }

        [[nodiscard]] bool operator==(const Status&) const = default;
    };
}

#pragma once

namespace PiSubmarine::Lamp::Telemetry::Api
{
    struct Status
    {
        bool IsActive = false;
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

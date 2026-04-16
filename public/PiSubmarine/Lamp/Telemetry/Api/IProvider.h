#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lamp/Telemetry/Api/Status.h"

namespace PiSubmarine::Lamp::Telemetry::Api
{
    class IProvider
    {
    public:
        virtual ~IProvider() = default;

        [[nodiscard]] virtual Error::Api::Result<Status> GetStatus() const = 0;
    };
}

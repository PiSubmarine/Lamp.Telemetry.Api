#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lamp/Telemetry/Api/IProvider.h"

namespace PiSubmarine::Lamp::Telemetry::Api
{
    class IProviderMock : public IProvider
    {
    public:
        MOCK_METHOD((Error::Api::Result<Status>), GetStatus, (), (const, override));
    };
}

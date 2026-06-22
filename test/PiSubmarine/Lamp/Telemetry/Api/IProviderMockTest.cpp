#include <gtest/gtest.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lamp/Telemetry/Api/IProviderMock.h"

namespace PiSubmarine::Lamp::Telemetry::Api
{
    TEST(IProviderMockTest, GetStatusReturnsConfiguredSnapshot)
    {
        IProviderMock providerMock;
        const auto expectedStatus = Status{
            .Intensity = NormalizedFraction{0.8},
            .HasOpenLoadFault = false,
            .HasOvercurrentFault = true,
            .HasOvertemperatureShutdownFault = false,
            .HasUndervoltageFault = false,
            .HasOvervoltageFault = false,
            .HasOvertemperatureWarning = true
        };

        EXPECT_CALL(providerMock, GetStatus())
            .WillOnce(testing::Return(Error::Api::Result<Status>(expectedStatus)));

        const auto result = providerMock.GetStatus();

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), expectedStatus);
    }
}

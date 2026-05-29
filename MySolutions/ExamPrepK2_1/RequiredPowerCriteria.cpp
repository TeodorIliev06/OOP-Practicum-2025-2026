#include "RequiredPowerCriteria.h"

RequiredPowerCriteria::RequiredPowerCriteria(std::string requiredPower)
	: requiredPower_(std::move(requiredPower)) {
}

std::optional<std::string> RequiredPowerCriteria::evaluate(const Application& application) const
{
	const auto& powers = application.getPowers();
	
	for (const auto& power : powers)
	{
		if (power == this->requiredPower_)
		{
			return std::nullopt;
		}
	}

	return std::format("Application {} does not have the required power: {}.", application.getCodeName(), this->requiredPower_);
}

std::unique_ptr<ICriteria> RequiredPowerCriteria::clone() const
{
    return std::make_unique<RequiredPowerCriteria>(*this);
}

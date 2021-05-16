//
//	Created by MarcasRealAccount on 16. May. 2021
//

#pragma once

#include "Engine/Renderer/Material/Uniform.h"

namespace gp1::renderer
{
	struct ReservedUniformBuffers
	{
	public:
		ReservedUniformBuffers();
		virtual ~ReservedUniformBuffers() = default;

		inline uint32_t GetCount() const
		{
			return static_cast<uint32_t>(m_UniformBuffers.size());
		}

		UniformBuffer*           GetUniformBuffer(const std::string& name);
		const UniformBuffer*     GetUniformBuffer(const std::string& name) const;
		std::shared_ptr<Uniform> GetUniform(const std::string& bufferName, const std::string& uniformName) const;

		template <typename T, std::enable_if_t<std::is_base_of_v<Uniform, T>, bool> = true>
		std::shared_ptr<T> GetUniform(const std::string& bufferName, const std::string& uniformName) const
		{
			return std::static_pointer_cast<T>(GetUniform(bufferName, uniformName));
		}

	public:
		static constexpr const uint32_t MaxUniformBufferCount = 8;

	protected:
		std::vector<UniformBuffer> m_UniformBuffers;
	};
} // namespace gp1::renderer
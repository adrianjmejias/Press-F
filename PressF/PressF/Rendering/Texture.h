#pragma once
#include "PressF/Core/OpenGL.h"
#include "PressF/AssetsManagement/Asset.h"

#define STB_IMAGE_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>



namespace PF
{

	enum class TexPixelType
	{
		FLOAT = GL_FLOAT,
		UNSIGNED_BYTE  = GL_UNSIGNED_BYTE
	};

	enum class TexColorFormat {
		RED = GL_RED,
		RGB = GL_RGB,
		RGBA = GL_RGBA,
		RGB_16F = GL_RGB16F,
		RGBA_16F = GL_RGBA16F,
	};

	enum class TexInterpolationMethod
	{
		LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR,
		LINEAR = GL_LINEAR,
		NEAREST = GL_NEAREST
	};

	enum class TexClampMethod
	{
		REPEAT = GL_REPEAT,
		CLAMP = GL_CLAMP_TO_EDGE,
	};

	enum class TexType
	{
		Texture2D = GL_TEXTURE_2D
	};

	struct Texture : GPUObject, Asset {
		Int width;
		Int height;
		Int nComponents;
		TexPixelType texPixelType;
		TexClampMethod sClamp, tClamp;
		TexInterpolationMethod sInterpolation, tInterpolation;
		TexColorFormat format = TexColorFormat::RED;
		TexColorFormat internalFormat{TexColorFormat::RGBA_16F};
		TexType texType{TexType::Texture2D};
		Texture() = default;
		Texture(TexColorFormat f, TexColorFormat inf, TexPixelType pType,int w, int h, unsigned char* data = nullptr)
		{
			*width = w;
			*height = h;
			internalFormat = inf;
			format = f;
			Generate();
			Reserve(data);
			SetInterpolationMethod(TexInterpolationMethod::LINEAR, TexInterpolationMethod::LINEAR);
			SetClampMethod(TexClampMethod::REPEAT, TexClampMethod::REPEAT);
		}


		void Reserve(unsigned char* data = nullptr)
		{
			glTexImage2D(static_cast<int>(texType), 0, static_cast<int>(format), width, height, 0, static_cast<int>(format), GL_UNSIGNED_BYTE, data);
		}
		void Generate();
		void SetInterpolationMethod(TexInterpolationMethod s, TexInterpolationMethod t);
		void SetClampMethod(TexClampMethod s, TexClampMethod t);
		static Owns<Texture> Texture::TextureFromFile(const std::string& _path);

		virtual void Bind() override;
		virtual void UnBind();
		~Texture();

		virtual void ImGui();
		void GPUInstantiate()
		{
			Generate();
			Bind();
			glTexImage2D(static_cast<int>(texType), 0, static_cast<int>(internalFormat), width, height, 0, static_cast<int>(format), static_cast<int>(texPixelType), NULL);
			glTexParameteri(static_cast<int>(texType), GL_TEXTURE_WRAP_S, static_cast<int>(sClamp));
			glTexParameteri(static_cast<int>(texType), GL_TEXTURE_WRAP_T, static_cast<int>(tClamp));
			glTexParameteri(static_cast<int>(texType), GL_TEXTURE_MIN_FILTER, static_cast<int>(sInterpolation));
			glTexParameteri(static_cast<int>(texType), GL_TEXTURE_MAG_FILTER, static_cast<int>(tInterpolation));

		}
	};

}
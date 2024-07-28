#pragma execution_character_set("utf-8")
#include"Image.h"

Image<1> convertSimpleMessageToImage(const vector<char>& message) {
	Image<1> img;
	img.dimensions = { message.size() };
	img.pixels.resize(message.size());
	// Convert each char to unsigned char and store in the pixels vector
	for (size_t i = 0; i < message.size(); ++i) {
		img.pixels[i] = static_cast<unsigned char>(message[i]);
	}
	return img;
}

Image<2> convertBlackWhiteToImage(const vector<vector<uint8_t>>& bwImage) {
	Image<2> img;
	img.dimensions = { bwImage.size(), bwImage[0].size() };
	img.pixels.reserve(bwImage.size() * bwImage[0].size());
	// Flatten the 2D vector into a 1D vector of pixels
	for (const auto& row : bwImage) {
		img.pixels.insert(img.pixels.end(), row.begin(), row.end());
	}
	return img;
}

Image<3> convertColorToImage(const vector<vector<vector<uint8_t>>>& colorImage) {
	Image<3> img;
	img.dimensions = { colorImage.size(), colorImage[0].size(), colorImage[0][0].size() };
	img.pixels.reserve(colorImage.size() * colorImage[0].size() * colorImage[0][0].size());
	// Flatten the 3D vector into a 1D vector of pixels
	for (const auto& channel : colorImage) {
		for (const auto& row : channel) {
			img.pixels.insert(img.pixels.end(), row.begin(), row.end());
		}
	}
	return img;
}

vector<char> convertImageToSimpleMessage(const Image<1>& img) {
	vector<char> message(img.pixels.size());
	// Convert each unsigned char back to char
	for (size_t i = 0; i < img.pixels.size(); ++i) {
		message[i] = static_cast<char>(img.pixels[i]);
	}
	return message;
}

vector<vector<uint8_t>> convertImageToBlackWhite(const Image<2>& img) {
	vector<vector<uint8_t>> bwImage(img.dimensions[0], vector<uint8_t>(img.dimensions[1]));
	size_t index = 0;
	// Reconstruct the 2D vector from the flattened pixels
	for (size_t i = 0; i < img.dimensions[0]; ++i) {
		for (size_t j = 0; j < img.dimensions[1]; ++j) {
			bwImage[i][j] = img.pixels[index++];
		}
	}
	return bwImage;
}

vector<vector<vector<uint8_t>>> convertImageToColor(const Image<3>& img) {
	vector<vector<vector<uint8_t>>> colorImage(img.dimensions[0],
		vector<vector<uint8_t>>(img.dimensions[1],
			vector<uint8_t>(img.dimensions[2])));
	size_t index = 0;
	// Reconstruct the 3D vector from the flattened pixels
	for (size_t c = 0; c < img.dimensions[0]; ++c) {
		for (size_t i = 0; i < img.dimensions[1]; ++i) {
			for (size_t j = 0; j < img.dimensions[2]; ++j) {
				colorImage[c][i][j] = img.pixels[index++];
			}
		}
	}
	return colorImage;
}

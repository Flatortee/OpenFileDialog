#pragma once
#include "Export.h"
#include "OpenFileDialog.hpp"

namespace sf
{
	template <typename T>
	class OPENFILEDIALOG_API OpenFileDialog_sfml
	{
	public:
		OpenFileDialog_sfml(OpenFileDialog::Filter flags = OpenFileDialog::AllFiles);

		~OpenFileDialog_sfml() = default;

	    const T & GetElement() const noexcept;
		T && GetElement_unique_ptr() noexcept;

	private:
		T m_element;
	};
}




#pragma once
#include "Export.h"
#include <windows.h>
#include <string>

class OPENFILEDIALOG_API OpenFileDialog
{
public:
	enum Filter
	{
		AllFiles = 1 << 0,		// Tous les fichiers
		Text = 1 << 1,			// Fichiers texte (*.txt)
		ImageJpeg = 1 << 2,		// Images JPEG (*.jpg, *.jpeg)
		ImagePng = 1 << 3,		// Images PNG (*.png)
		ImageBmp = 1 << 4,		// Images BMP (*.bmp)
		ImageGif = 1 << 5,		// Images GIF (*.gif)
		Pdf = 1 << 6,			// Documents PDF (*.pdf)
		Word = 1 << 7,			// Documents Word (*.doc, *.docx)
		Excel = 1 << 8,			// Documents Excel (*.xls, *.xlsx)
		PowerPoint = 1 << 9,	// Pr�sentations PowerPoint (*.ppt, *.pptx)
		AudioMp3 = 1 << 10,		// Audio MP3 (*.mp3)
		AudioWav = 1 << 11,		// Audio WAV (*.wav)
		VideoMp4 = 1 << 12,		// Vid�o MP4 (*.mp4)
		VideoAvi = 1 << 13,		// Vid�o AVI (*.avi)
		ArchiveZip = 1 << 14,	// Archives ZIP (*.zip)
		ArchiveRar = 1 << 15,	// Archives RAR (*.rar)
		SourceCpp = 1 << 16,	// Fichiers C++ (*.cpp, *.h)
		SourceC = 1 << 17,		// Fichiers C (*.c, *.h)
		SourcePython = 1 << 18,	// Fichiers Python (*.py)
		SourceJava = 1 << 19,	// Fichiers Java (*.java)
		SourceCs = 1 << 20		// Fichiers C# (*.cs)
	};

	OpenFileDialog(Filter flags = AllFiles);
	~OpenFileDialog() = default;

	std::string Open(Filter flags = AllFiles);
	std::string GetFileSaved() const;
	void SetInitialDirectory(const std::wstring& dir);
private:
	std::wstring BuildFilterString(Filter flags);
	std::wstring m_initialDirectory;
	std::string m_fileSaved;
};

/* EXAMPLE D'UTILISATION
void ExempleOpenFileDialog()
{
	OpenFileDialog::Filter flags = static_cast<OpenFileDialog::Filter>(OpenFileDialog::Text | OpenFileDialog::ImageJpeg | OpenFileDialog::Pdf);
	
	// Exemple 1
	OpenFileDialog dialog;
	dialog.Open(flags);

	// Exemple 2
	OpenFileDialog dialog2(flags);
	std::string filePath = dialog2.GetFileSaved();
}
*/
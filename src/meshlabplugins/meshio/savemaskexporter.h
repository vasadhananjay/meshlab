/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

/****************************************************************************
  History

 $Log$
 Revision 1.5  2006/01/16 15:30:26  fmazzant
 added rename texture dialog for exporter
 removed old maskobj

 Revision 1.4  2006/01/16 11:49:48  fmazzant
  added base texture name option.

 Revision 1.3  2006/01/15 00:45:39  fmazzant
 extend mask exporter for all type file format +

 Revision 1.2  2006/01/14 11:23:24  fmazzant
 update savemask exporter with init a mask [base type]

 Revision 1.1  2006/01/13 23:59:51  fmazzant
 first commit exporter dialog


 ****************************************************************************/

#ifndef __VCGLIB_SAVEMASK_EXPORT
#define __VCGLIB_SAVEMASK_EXPORT

#include <wrap/io_trimesh/io_mask.h>

#include "../../meshlab/meshmodel.h"
#include "ui_savemaskexporter.h"

class SaveMaskExporterDialog : public QDialog
{
	Q_OBJECT
public:
	SaveMaskExporterDialog(QWidget *parent);
	SaveMaskExporterDialog(QWidget *parent,int &mask);
	SaveMaskExporterDialog(QWidget *parent,int &mask,int type);
	SaveMaskExporterDialog(QWidget *parent,MeshModel &m,int type);

	void Initialize();
	void SetDisableChecks(int type);
	void SetTextureName();
	int GetNewMask();

private slots:
	void SlotOkButton();
	void SlotCancelButton();
	void SlotRenameTexture();
	void SlotSelectionTextureName();

private:
	Ui::MaskExporterDialog ui;
	MeshModel m;
	int mask;
	int type;
};//end class

namespace vcg {
namespace tri {
namespace io {
	
	class SaveMaskToExporter
	{
	public:	

		enum FileType
		{
			_OBJ, //0
			_PLY, //1
			_OFF, //2
			_STL, //3
			_3DS  //4
		};

		inline static int GetMaskToExporter(MeshModel &m,int type)
		{
			SaveMaskExporterDialog dialog(new QWidget(),m,type);
			dialog.Initialize();
			dialog.exec();
			int newmask = dialog.GetNewMask();
			dialog.close();
			return newmask;
		}
	};
} // end Namespace tri
} // end Namespace io
} // end Namespace vcg

#endif
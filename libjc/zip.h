
/*
 * @COPYRIGHT@
 *
 * $Id: zip.h,v 1.1 2005/05/24 01:09:38 archiecobbs Exp $
 */

#ifndef _ZIP_H_
#define _ZIP_H_

/*
 * ZIP file constants.
 */
#define ZIP_DIRECTORY_SIGNATURE		0x06054b50
#define ZIP_DIRENTRY_SIGNATURE		0x02014b50
#define ZIP_ENTRY_SIGNATURE		0x03044b50
#define ZIP_DIRECTORY_INFO_LEN		22
#define ZIP_LOCAL_HEADER_EXTRA_OFFSET	28
#define ZIP_LOCAL_HEADER_LEN		30

#define ZIP_METHOD_STORED 		0
#define ZIP_METHOD_DEFLATED 		8

/*
 * ZIP structures.
 */
typedef struct _jc_zip		_jc_zip;
typedef struct _jc_zip_entry	_jc_zip_entry;

struct _jc_zip_entry {
	char		*name;
	jshort		method;
	jint		comp_len;
	jint		uncomp_len;
	jint		crc;
	off_t		offset;
};

struct _jc_zip {
	int		fd;
	char		*path;
	int		num_entries;
	_jc_zip_entry	*entries;
};

#endif	/* _ZIP_H_ */

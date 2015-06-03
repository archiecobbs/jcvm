
//
// @COPYRIGHT@
//
// $Id: ObjectGenerator.java,v 1.1.1.1 2004/02/20 05:15:19 archiecobbs Exp $
//

package org.dellroad.jc;

import java.io.File;

/**
 * Interface implemented by classes that generate JC ELF object
 * files from raw class files.
 */
public interface ObjectGenerator {

	/**
	 * Generate the ELF object file for the named class
	 * and write it into the file.
	 *
	 * @param className Class name (with slashes, not dots)
	 * @param finder Object capable of retrieving class files
	 * @param file Where to put resulting ELF object
	 */
	public void generateObject(String className,
	    ClassfileFinder finder, File file) throws Exception;

	/**
	 * Determine if an ELF object file is valid for the named class
	 * and all other classes (available through the provided
	 * <code>finder</code>) on which the object file may depend.
	 *
	 * @param className Class name (with slashes, not dots)
	 * @param finder Class finder capable of retrieving class files
	 * @param file Where to put resulting ELF object
	 */
	public boolean objectIsValid(String className,
	    ClassfileFinder finder, File file) throws Exception;
}


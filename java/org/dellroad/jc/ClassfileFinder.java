
//
// @COPYRIGHT@
//
// $Id: ClassfileFinder.java,v 1.1.1.1 2004/02/20 05:15:19 archiecobbs Exp $
//

package org.dellroad.jc;

/**
 * Represents objects capable of retrieving class files.
 */
public interface ClassfileFinder {

	/**
	 * Retrieve the class file that is used to define the named class.
	 * This is a capability specific to the JC virtual machine.
	 *
	 * @param className Class name (with slashes, not dots)
	 * @throws ClassNotFoundException if class is not found
	 */
	public byte[] getClassfile(String className)
		throws ClassNotFoundException;

	/**
	 * Return the hash of the bytes that would be returned by
	 * {@link #getClassfile getClassfile()} with the same arguments.
	 * The hash of a class file is defined as the last 16 bytes
	 * of the MD5 of the class file.
	 *
	 * @param className Class name (with slashes, not dots)
	 * @throws ClassNotFoundException if class is not found
	 */
	public long getClassfileHash(String className)
		throws ClassNotFoundException;
}


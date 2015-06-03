
//
// @COPYRIGHT@
//
// $Id: JCFinder.java,v 1.1.1.1 2004/02/20 05:15:19 archiecobbs Exp $
//

package org.dellroad.jc;

/**
 * Gateway into the JC virtual machine for retrieving class files.
 */
public class JCFinder implements ClassfileFinder {

	private final ClassLoader loader;

	/**
	 * Create a new finder that uses the given class loader
	 * to pull in not-before-seen class files as necessary.
	 */
	public JCFinder(ClassLoader loader) {
		this.loader = loader;
	}

	public byte[] getClassfile(String className)
	    throws ClassNotFoundException {
		try {
			return getClassfile(className, loader);
		} catch (NoClassDefFoundError e) {
			throw new ClassNotFoundException(e.getMessage());
		}
	}

	public long getClassfileHash(String className)
	    throws ClassNotFoundException {
		try {
			return getClassfileHash(className, loader);
		} catch (NoClassDefFoundError e) {
			throw new ClassNotFoundException(e.getMessage());
		}
	}

	private static native byte[] getClassfile(String className,
	    ClassLoader loader);

	private static native long getClassfileHash(String className,
	    ClassLoader loader);
}


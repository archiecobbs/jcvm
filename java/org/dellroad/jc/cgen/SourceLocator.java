
//
// @COPYRIGHT@
//
// $Id: SourceLocator.java,v 1.1.1.1 2004/02/20 05:15:26 archiecobbs Exp $
//

package org.dellroad.jc.cgen;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import soot.Singletons;
import soot.util.ClassInputStream;
import org.dellroad.jc.ClassfileFinder;

/**
 * Implementation of Soot's {@link soot.util.SourceLocator} interface
 * used by the {@link SootCodeGenerator} class. In order for
 * Soot to pick up and analyze the correct class files, we must
 * provide our own implementation which retrieves them from the
 * JC virtual machine. This ensures that no matter how any particular
 * ClassLoader retrieves a class file, that exact same class file
 * will be made available to Soot for analysis.
 */
public class SourceLocator extends soot.util.SourceLocator {

	private ClassfileFinder finder;

	public SourceLocator(Singletons.Global g) {
		super(g);
	}

	public void setFinder(ClassfileFinder finder) {
		this.finder = finder;
	}

	/**
	 * Retrieve the classfile contents for the named class,
	 * as loaded by the ClassLoader associated with this object.
	 */
	public InputStream getInputStreamOf(String className)
	    throws ClassNotFoundException {
		return new ClassInputStream(
		    new ByteArrayInputStream(
		    finder.getClassfile(className)));
	}
}


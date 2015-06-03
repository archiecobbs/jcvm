
//
// @COPYRIGHT@
//
// $Id: CodeGenerator.java,v 1.2 2004/07/13 03:36:20 archiecobbs Exp $
//

package org.dellroad.jc.cgen;

import java.io.OutputStream;
import org.dellroad.jc.ClassfileFinder;

/**
 * Interface for objects that can generate C source code and header files
 * that conform to the JC C source file standard.
 */
public interface CodeGenerator {

	/**
	 * Generate the C header file for the given class.
	 *
	 * @param className name of the class who's header file we're generating
	 * @param finder a way to acquire Java class files
	 * @param output where to write the generated header file to
	 */
	public void generateH(String className, ClassfileFinder finder,
	    OutputStream output) throws Exception;

	/**
	 * Generate the C source file for the given class.
	 *
	 * @param className name of the class who's C file we're generating
	 * @param finder a way to acquire Java class files
	 * @param output where to write the generated C file to
	 */
	public void generateC(String className, ClassfileFinder finder,
	    OutputStream output) throws Exception;

	/**
	 * Reset state.
	 *
	 * <p>
	 * Currently only one CodeGenerator instance will be
	 * in use at a time. Before and after each use, this
	 * method is invoked. A good oportunity to free objects
	 * that are no longer needed, (re)initialize state, etc.
	 */
	public void reset();
}


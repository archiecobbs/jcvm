
//
// @COPYRIGHT@
//
// $Id: TypeAnalysis.java,v 1.6 2005/03/19 22:18:20 archiecobbs Exp $
//

package org.dellroad.jc.cgen.analysis;

import java.util.*;
import org.dellroad.jc.cgen.Util;
import soot.*;
import soot.jimple.*;
import soot.toolkits.scalar.*;

/**
 * Determines the run-time type of a reference local as best we can based on
 * information provided by a {@link LocalDefs LocalDefs} object.
 */
public class TypeAnalysis {

	private final LocalDefs localDefs;

	private final AbstractJimpleValueSwitch vs
	    = new AbstractJimpleValueSwitch() {
		public void caseNewArrayExpr(NewArrayExpr v) {
			setResult(v.getType());
		}
		public void caseNewMultiArrayExpr(NewMultiArrayExpr v) {
			setResult(v.getType());
		}
		public void caseNewExpr(NewExpr v) {
			setResult(v.getType());
		}
		public void caseNullConstant(NullConstant v) {
			setResult(v.getType());
		}
		public void defaultCase(Object obj) {
			Value v = (Value)obj;
			Type type = v.getType();
			if (!(v.getType() instanceof RefType))
				return;
			SootClass c = ((RefType)type).getSootClass();
			if (!Util.isFinal(c))
				return;
			setResult(type);
		}
	};

	public TypeAnalysis(LocalDefs localDefs) {
		this.localDefs = localDefs;
	}

	/**
	 * Return the exact type of the reference local def if it's a reference
	 * type and the Java class is known exactly, else <code>null</code>.
	 */
	public RefLikeType getExactType(Local local, Unit unit) {
		RefLikeType type = null;
		for (Iterator i = localDefs.getDefsOfAt(local, unit).iterator();
		    i.hasNext(); ) {
			DefinitionStmt def = (DefinitionStmt)i.next();
			vs.setResult(null);
			def.getRightOp().apply(vs);
			RefLikeType type2 = (RefLikeType)vs.getResult();
			if (type2 == null)
				return null;
			if (type == null)
				type = type2;
			else if (!type.equals(type2))
				return null;
		}
		return type;
	}
}


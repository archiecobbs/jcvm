<?php

require("jcvm.php");
jcvm_header("Home");

$release="1.4.7";

?>

<h3>Welcome to JC!</h3>

<p>
JC is a Java virtual machine implementation that converts class files
into C source files using the 
<a href="http://www.sable.mcgill.ca/soot/" class="link">Soot</a> Java bytecode
analysis framework, compiles them with GCC, and loads them using a
built-in ELF object file loader. JC utilizes the
<a href="http://www.classpath.org/" class="link">GNU Classpath</a> class library
and provides a fairly complete Java runtime including sophisticated
optimizations to increase runtime performance.
JC also includes a bytecode interpreter, and supports execution in either or mixed modes.
</p>

<p>
Although JC has good interpreter performance, JC doesn't try to be
fast in every situation. Instead, JC focuses on this question: how
fast can we go if we know some or all of the class files ahead of
time? The answer is: very fast! Optimizations that are just too
complex and expensive to perform at runtime are instead performed
at code generation time. JC's code generator is written in Java,
using the powerful Soot bytecode analysis framework. When combined
with the proven power of GCC's C optimizer the results are impressive.
As an additional benefit, JC contains very little architecture-specific
code and is highly portable.
</p>

<p>
JC features include:

<blockquote>
&diams; Conversion of Java bytecode into C and optimized compilation using GCC into ELF object files
resulting in <b>fast</b> execution.<br/>
&diams; Java bytecode interpreter with support for compiled, interpreted,
and mixed mode execution.<br/>
&diams; Sophisticated code generation optimizations including method inlining, allocation of non-escaping objects on the stack, method ``nonvirtualization,'' array bounds check elimination, redundant cast elimination, redundant null pointer check elimination, and class initialization check on first "active use" elimination.<br/>
&diams; On-demand or pre-generated object creation, with the ability to create ``main class'' executables.<br/>
&diams; Complete thread support based on the POSIX <code>pthread(3)</code> library, including <code>Thread.interrupt()</code>, <code>Thread.suspend()</code>, <code>Thread.resume()</code>, and <code>Thread.stop()</code>.<br/>
&diams; Complete Java Native Interface (JNI 1.4) support, plus a zero overhead JC Native Interface (JCNI).<br/>
&diams; Complete Java 2 style class loader support, including class loader garbage collection and unloading.<br/>
&diams; Complete Java reflection API implementation.<br/>
&diams; Support for object finalization and for soft, weak, and phantom references.<br/>
&diams; All object pointers are direct pointers. Non-copying "stop the world" mark and sweep garbage collector.<br/>
&diams; Utilizes a stock installation of the <a href="http://www.classpath.org/" class="link">GNU Classpath</a> Java class library.<br/>
&diams; Interface method dispatch using "quick" hash tables resulting in one extra pointer dereference (typically) over virtual method dispatch.<br/>
&diams; Flexible usage of ELF object files: multiple ELF objects may be linked together into a single object file (JC will then load all of the defined types simultaneously); class files are not required once ELF objects have been generated from them.<br/>
&diams; Use of the <a href="http://www.sable.mcgill.ca/soot/" class="link">Soot</a> framework for sophisticated bytecode analysis, optimization, and code generation.<br/>
&diams; Innovative spin-free thin lock algorithm from <a href="http://www.sablevm.org/" class="link">SableVM</a>.<br/>
&diams; Use of signals for efficient detection of null pointer dereferences, divide by zero, and for inter-thread communication.<br/>
</blockquote>
</p>

<p>
You can learn more about JC by reading the 
<a href="share/jc/doc/jc.html" class="link">manual</a>.
</p>

<h3>Latest News</h3>

<blockquote>
<b>13 Nov 2005</b> JC 1.4.7 is released. This is a minor bug-fix release.
It also updates to Classpath version 0.19.
See the <a href="share/jc/doc/CHANGES" class="link">CHANGES</a> file
for details.
</blockquote>

<blockquote>
<b>23 Jul 2005</b> JC 1.4.6 is released. This is a minor bug-fix release.
It also updates to Classpath version 0.17.
See the <a href="share/jc/doc/CHANGES" class="link">CHANGES</a> file
for details.
</blockquote>

<blockquote>
<b>15 May 2005</b> JC 1.4.5 is released. This is a minor bug-fix release.
It also updates to Classpath version 0.15.
See the <a href="share/jc/doc/CHANGES" class="link">CHANGES</a> file
for details.
</blockquote>

<blockquote>
<b>10 May 2005</b> JC 1.4.4 is released. This release adds support for
different calling conventions in generated JCNI code, and with this
support enables <b>passing of function parameters in the %eax, %edx,
and %ecx registers</b> on the i386 architecture. It also fixes a bug
in method interface dispatch for certain methods having float parameters.
See the <a href="share/jc/doc/CHANGES" class="link">CHANGES</a> file
for details.
</blockquote>

<blockquote>
<b>25 Apr 2005</b> JC 1.4.3 is released. This is a maintenance release fixing
a stack crawling bug on newer versions of FreeBSD. It also removes the dependence
on <b>libffi</b>. See the <a href="share/jc/doc/CHANGES"
class="link">CHANGES</a> file for details.
</blockquote>

<blockquote>
<b>14 Apr 2005</b> JC 1.4.2 is released. This is a maintenance release
containing a couple of important bug fixes.
See the <a href="share/jc/doc/CHANGES"
class="link">CHANGES</a> file for details.
</blockquote>

<h3>Download</h3>

<blockquote>
<a href="http://sourceforge.net/project/showfiles.php?group_id=102198" class="link">Click here</a> to download the <code>jc-<?php print $release; ?>.tgz</code> distribution.
You can read the <a href="share/jc/doc/INSTALL" class="link">installation instructions</a> to get
a feel for what's involved in building and installing JC.
</blockquote>

<h3>Documentation</h3>

<blockquote>
<p>
The <a href="share/jc/doc/jc.html" class="link">manual</a> contains details
about how JC works and is included in the distribution.
</p>

<p>
Also included is <a href="share/jc/doc/api/index.html" class="link">Javadoc documentation</a>
for the Java classes used by JC to generate ELF objects from class files.
</p>
</blockquote>

<h3>Mailing List</h3>

<blockquote>
Join the <a href="http://lists.sourceforge.net/lists/listinfo/jcvm-general" class="link"><code>jcvm-general</code></a> mailing list to participate in
discussions and give feedback.
</blockquote>

<h3>SourceForge project page</h3>

<blockquote>
The JC project is hosted by
<a href="http://sourceforge.net/projects/jcvm" class="link">SourceForge</a>.
Go to the <b>jcvm</b> SourceForge
<a href="http://sourceforge.net/projects/jcvm" class="link">
<b>project page</b></a>.
</blockquote>


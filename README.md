# Linux-Commands

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Linux Command Implementation in C</title>
</head>
<body>
    <h1>Linux Command Implementation in C</h1>
    <p>This branch contains implementations of three commonly used Linux commands - <code>grep</code>, <code>cat</code>, and <code>echo</code> - written in the C programming language.</p>
    <h2>Commands Implemented</h2>
    <ol>
        <li><strong>grep</strong>: Searches for a specified pattern in one or more files.</li>
        <li><strong>cat</strong>: Concatenates files and prints them to standard output.</li>
        <li><strong>echo</strong>: Prints its arguments to standard output.</li>
    </ol>
    <h2>How to Use</h2>
    <ol>
        <li>Clone the repository:
            <pre><code>git clone &lt;repository_url&gt;</code></pre>
        </li>
        <li>Checkout to this branch:
            <pre><code>git checkout &lt;branch_name&gt;</code></pre>
        </li>
        <li>Compile the source code:
            <pre><code>gcc -o grep grep.c<br>gcc -o cat cat.c<br>gcc -o echo echo.c</code></pre>
        </li>
        <li>Run the commands:
            <ul>
                <li>For <code>grep</code>:
                    <pre><code>./grep &lt;pattern&gt; &lt;file1&gt; &lt;file2&gt; ...</code></pre>
                </li>
                <li>For <code>cat</code>:
                    <pre><code>./cat &lt;file1&gt; &lt;file2&gt; ...</code></pre>
                </li>
                <li>For <code>echo</code>:
                    <pre><code>./echo &lt;message&gt;</code></pre>
                </li>
            </ul>
        </li>
    </ol>
    <h2>Examples</h2>
    <ul>
        <li><strong>grep</strong>: Search for the word "example" in a file named "text.txt":
            <pre><code>./grep example text.txt</code></pre>
        </li>
        <li><strong>cat</strong>: Print the content of a file:
            <pre><code>./cat file1.txt file2.txt</code></pre>
        </li>
        <li><strong>echo</strong>: Print the message "Hello, world!":
            <pre><code>./echo "Hello, world!"</code></pre>
        </li>
    </ul>

</body>
</html>

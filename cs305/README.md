# CS 305 Journal
## Client Description
Artemis Financial is a financial services organization that provides numerous banking and investment products to the general public. This company hired our consulting agency to strengthen its security posture for its online tools.

## What did you do well when you found your client's software security vulnerabilities? 
Immediately identified that the versions of all packages and dependencies and the Java version were horrifically outdated, exposing the client to over a hundred known and exploited vulnerabilities.

## Why is it important to code securely? 
When developed without security practices in the development cycle, all projects, large or small, can cause significant data breaches when known exploitable patterns or insecure software packages are used. Never assume that a bad actor can't access the project.

## What value does software security add to a company's overall well-being?
A development culture that includes a robust software security mindset can mitigate the effects of potential bad actors by reducing the threat vectors and limiting the exposure of sensitive data. No practices are fool-proof for motivated actors, but implementing best practices raises the bar of effort required to cause a breach.

## Which part of the vulnerability assessment was challenging or helpful to you?
Setting up the development environment was initially challenging because the software package was outdated.

## How did you increase layers of security? 
Created and deployed a proper SSL certificate, deployed a solid cipher for hashing sensitive data, and updated all of the dependencies to their most recent versions.

## In the future, what would you use to assess vulnerabilities and decide which mitigation techniques to use?
Add tools like Dependabot and Sonarqube to the CI/CD pipeline to detect vulnerabilities and package updates on each pull request before it is committed to the main branch and deployed to production.

## How did you make certain the code and software application were functional and secure? 
Used tools like the Dependency Check to detect known vulnerabilities and manually checked the code to ensure best practices were followed.

## After refactoring the code, how did you check to see whether you introduced new vulnerabilities?
Re-scanned the code with Dependency Check. Deployed the code and verified that the SSL certificate was correctly served and verified.

## What resources, tools, or coding practices did you use that might be helpful in future assignments or tasks?
Tools will always vary with the languages used. If a future project were to use Java, I would use the Dependency Check tool again. The textbook emphasized the importance of sanitizing untrusted input from outside users. I would ensure that the best patterns are used for the various languages and tools for this purpose.

## Employers sometimes ask for examples of work that you have successfully completed to show your skills, knowledge, and experience. What might you show future employers from this assignment?
Truthfully, the assignments from this course are so far out of date that almost nothing of value could be shown that I haven't already done better in my professional career.
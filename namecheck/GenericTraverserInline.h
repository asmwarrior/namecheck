/**
* @brief this sets the visitor and traverse the given namespace.
*
*
* @param ns this should be the global namespace to process.
* @param visitor the visitor to set.
*/
inline void traverse(const GenericTree ns, GenericVisitor* visitor)
{
    _visitor = visitor;
    traverse(ns);
}
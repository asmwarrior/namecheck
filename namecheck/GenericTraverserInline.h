inline void traverse(const GenericTree ns, GenericVisitor* visitor)
{
    _visitor = visitor;
    traverse(ns);
}